let path = [];
let draggingIndex = -1;
let gridSize = 10; // Default grid size is now 10
let fieldImage;
let panX = 0;
let panY = 0;
let isPanning = false;
let undoStack = [];

// URLs for the field images
const fieldImages = {
    v5rc: "https://raw.githubusercontent.com/NoozAbooz/210K-HighStakes-2025/V1/website/path/V5RC-HighStakes-H2H-2000x2000.png",
    "v5rc-skills": "https://raw.githubusercontent.com/NoozAbooz/210K-HighStakes-2025/V1/website/path/V5RC-HighStakes-Skills-2000x2000.png"
};

// Preload the field image based on selection
function preload() {
    updateFieldImage();
}

// Setup the canvas and initial configurations
function setup() {
    let canvasSize = min(windowWidth, windowHeight - 60);
    let canvas = createCanvas(canvasSize, canvasSize);
    canvas.parent('canvas-container');
    windowResized();
    document.getElementById('canvas-container').addEventListener('contextmenu', e => e.preventDefault()); // Disable right-click context menu

    // Setup for undo functionality
    window.addEventListener('keydown', handleUndo);
}

// Draw loop to render the field, grid, and path
function draw() {
    background(45);
    translate(panX, panY);
    if (fieldImage) {
        image(fieldImage, 0, 0, width, height);
    }
    drawGrid();
    drawPath();
}

// Draw the grid lines, aligned with the field tiles
function drawGrid() {
    stroke(100, 100, 100, 15); // Updated stroke for grid lines
    for (let i = 0; i <= width; i += gridSize) {
        line(i, 0, i, height);
        line(0, i, width, i);
    }
}

// Handle resizing of the canvas when the window is resized
function windowResized() {
    let canvasSize = min(windowWidth, windowHeight - 60);
    resizeCanvas(canvasSize, canvasSize);
}

// Update the field image based on the selected field
function updateFieldImage() {
    let fieldType = document.getElementById('field-select').value;
    fieldImage = loadImage(fieldImages[fieldType]);
}

// Update grid density based on user input
function updateGridDensity() {
    gridSize = parseInt(document.getElementById('grid-density').value);
}

// Handle mouse pressed events for adding, dragging, or removing waypoints
function mousePressed() {
    if (mouseButton === LEFT) {
        if (isPanning) return;

        let x = Math.round((mouseX - panX) / gridSize) * gridSize;
        let y = Math.round((mouseY - panY) / gridSize) * gridSize;

        // Ensure waypoints are within field image boundaries
        if (x >= 0 && x <= width && y >= 0 && y <= height) {
            draggingIndex = path.findIndex(p => dist(mouseX - panX, mouseY - panY, p.x + gridSize / 2, p.y + gridSize / 2) < 20);
            if (draggingIndex === -1) {
                path.push({ x, y, angle: 0 });
                undoStack.push([...path]); // Save state for undo
                generateCode();
            }
        }
    } else if (mouseButton === RIGHT) {
        // Remove the waypoint if right-clicked within the halo
        path = path.filter(p => dist(mouseX - panX, mouseY - panY, p.x + gridSize / 2, p.y + gridSize / 2) >= 20);
        undoStack.push([...path]); // Save state for undo
        generateCode();
    } else if (mouseButton === CENTER) {
        isPanning = true;
    }
    return false;
}

// Handle dragging of waypoints
function mouseDragged() {
    if (isPanning) {
        panX += movedX;
        panY += movedY;
    } else if (draggingIndex !== -1) {
        let x = Math.round((mouseX - panX) / gridSize) * gridSize;
        let y = Math.round((mouseY - panY) / gridSize) * gridSize;

        // Ensure waypoints remain within field image boundaries
        if (x >= 0 && x <= width && y >= 0 && y <= height) {
            path[draggingIndex].x = x;
            path[draggingIndex].y = y;
            generateCode();
        }
    }
}

// Stop dragging when the mouse is released
function mouseReleased() {
    if (draggingIndex !== -1) {
        undoStack.push([...path]); // Save state for undo
        draggingIndex = -1;
    }
    isPanning = false;
}

// Handle undo operation (Ctrl + Z)
function handleUndo(event) {
    if (event.ctrlKey && event.key === 'z') {
        if (undoStack.length > 0) {
            path = undoStack.pop();
            generateCode();
        }
    }
}

// Draw the path, waypoints, and direction indicators
function drawPath() {
    if (path.length > 0) {
        stroke(0, 255, 255);
        strokeWeight(3);
        noFill();
        beginShape();
        for (let point of path) {
            vertex(point.x + gridSize / 2, point.y + gridSize / 2);
        }
        endShape();

        for (let i = 0; i < path.length; i++) {
            // Draw waypoint halos
            if (i === 0) {
                fill(255, 100, 100, 150); // Red translucent halo for the starting waypoint
            } else {
                fill(255, 255, 255, 100); // Translucent white halo for other waypoints
            }
            noStroke();
            ellipse(path[i].x + gridSize / 2, path[i].y + gridSize / 2, 40); // 40px diameter halo
        }

        // Draw waypoint labels on top of halos and lines
        for (let i = 0; i < path.length; i++) {
            fill(0);
            textAlign(CENTER, CENTER);
            text(i + 1, path[i].x + gridSize / 2, path[i].y + gridSize / 2);
        }
    }
}

// Clear the path and update the code output
function clearPath() {
    path = [];
    undoStack.push([...path]); // Save state for undo
    generateCode();
}

// Reset the field view (new function)
function resetView() {
    panX = 0;
    panY = 0;
}

// Generate the autonomous path code and display it in the output box
function generateCode() {
    if (path.length === 0) {
        document.getElementById('code-output').textContent = "// No waypoints set.";
        return;
    }

    let firstWaypoint = path[0];
    let code = "// Autonomous Path Code\n";
    code += `// Starting point: (${firstWaypoint.x}, ${firstWaypoint.y})\n`;
    code += `chassis.set_drive_pid(${path.length * 10}, 100, 1000, 0, 0.0, 0.0);\n`;

    for (let i = 0; i < path.length; i++) {
        let relativeX = path[i].x - firstWaypoint.x;
        let relativeY = path[i].y - firstWaypoint.y;
        
        // Rotate coordinates based on the first waypoint's orientation
        let angle = firstWaypoint.angle;
        let rotatedX = relativeX * cos(angle) - relativeY * sin(angle);
        let rotatedY = relativeX * sin(angle) + relativeY * cos(angle);

        code += `chassis.drive_to_relative_point(${rotatedX.toFixed(2)}, ${rotatedY.toFixed(2)}); // Point ${i + 1}\n`;
    }

    document.getElementById('code-output').textContent = code;
}

// Copy the generated code to the clipboard
function copyCodeToClipboard() {
    const codeOutput = document.getElementById('code-output');
    const textArea = document.createElement('textarea');
    textArea.value = codeOutput.textContent;
    document.body.appendChild(textArea);
    textArea.select();
    document.execCommand('copy');
    document.body.removeChild(textArea);

    // Show toast notification
    showToast();
}

// Function to display the toast notification
function showToast() {
    const toast = document.getElementById('toast');
    toast.classList.add('show');
    setTimeout(() => {
        toast.classList.remove('show');
    }, 3000);
}
