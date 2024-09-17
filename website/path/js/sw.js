const cacheName = 'vex-path-planner-v1';
const cacheUrls = [
    '../index.html',
    '../styles.css',
    '../manifest.json',
    '../favicon.png',
    './depend/p5.min.js',
    './editor.js',
    './generator.js',
    './main.js',
    './save.js',
    './sw.js',
    '../images/V5RC-HighStakes-H2H-2000x2000.png',
    '../images/V5RC-HighStakes-Skills-2000x2000.png'
];

// Installing Service Worker
self.addEventListener('install', (e) => {
  console.log('[Service Worker] Install');
  e.waitUntil((async () => {
    const cache = await caches.open(cacheName);
    console.log('[Service Worker] Caching all content');

    const stack = [];
    cacheUrls.forEach(file => stack.push(
        cache.add(file).catch(_=>console.error(`can't load ${file} to cache`))
    ));
    return Promise.all(stack);
    //await cache.addAll(cacheUrls);
  })());
});

// Fetching content using Service Worker
self.addEventListener('fetch', (e) => {
    // Cache http and https only, skip unsupported chrome-extension:// and file://...
    if (!(
       e.request.url.startsWith('http:') || e.request.url.startsWith('https:')
    )) {
        return; 
    }

  e.respondWith((async () => {
    const r = await caches.match(e.request);
    console.log(`[Service Worker] Fetching resource: ${e.request.url}`);
    if (r) return r;
    const response = await fetch(e.request);
    const cache = await caches.open(cacheName);
    console.log(`[Service Worker] Caching new resource: ${e.request.url}`);
    cache.put(e.request, response.clone());
    return response;
  })());
});