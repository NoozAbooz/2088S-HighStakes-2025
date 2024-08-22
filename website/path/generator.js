// Generate the autonomous path code and display it in the output box
function generateCode() {
    if (path.length === 0) {
        document.getElementById('code-output').textContent = "// No waypoints set.";
        return;
    }
    
    if (loadedSlotIndex !== null) {
        saveSlots[loadedSlotIndex].waypoints = [...path]; // Overwrite waypoints
        saveSlots[loadedSlotIndex].modified = new Date().toLocaleString(); // Update modified date
        saveSlotsToLocalStorage(); // Save to local storage
        renderSaveSlots(); // Re-render save slots
    }

    const formatSelect = document.getElementById('format-select');
    const selectedConfig = formatSelect.value;

    if (selectedConfig === 'libks-mtpoint') {
        let firstWaypoint = path[0];

        let code = "// libKS MTPoint v0.1\n";
        code += `// Starting point: (${((firstWaypoint.x - (canvasSize / 2)) / canvasSize * 144).toFixed(2)} in, ${((firstWaypoint.y  - (canvasSize / 2)) / canvasSize * -144).toFixed(2)} in)\n`;
        //code += `chassis.set_drive_pid(${path.length * 10}, 100, 1000, 0, 0.0, 0.0);\n`;

        for (let i = 0; i < path.length; i++) {
            let relativeX = (path[i].x - firstWaypoint.x) / canvasSize * 144;
            let relativeY = (path[i].y - firstWaypoint.y) / canvasSize * 144;

            // Rotate coordinates based on the first waypoint's orientation
            let angle = firstWaypoint.angle;
			let h = ((360 - angle) + 90) % 360;
            let rotatedX = relativeX * cos(h);
            let rotatedY = relativeY * sin(h);

            if (path[i].angularDirection === "auto" && i != 0) {
                code += `chassis.turnToHeading(${path[i].angle}, ${path[i].timeout}); // Point ${i + 1}\n`;
            } else if (path[i].angularDirection === "clockwise" && i != 0) {
                code += `chassis.turnToHeading(${path[i].angle}, ${path[i].timeout}, {.direction = AngularDirection::CW_CLOCKWISE}); // Point ${i + 1}\n`;
            } else if (path[i].angularDirection === "counter-clockwise" && i != 0) {
                code += `chassis.turnToHeading(${path[i].angle}, ${path[i].timeout}, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}); // Point ${i + 1}\n`;
            }

            code += `chassis.moveToPoint(${rotatedX.toFixed(2)}, ${rotatedY.toFixed(2)}, ${path[i].timeout}, {.forwards = ${path[i].forwards}, .maxSpeed = ${path[i].maxSpeed}, .minSpeed = ${path[i].minSpeed}}); // Point ${i + 1}\n`;
            document.getElementById('code-output').textContent = code;
        }
    }

    //console.log(path);
}