const CACHE_NAME = 'vex-path-planner-v1';

self.addEventListener('install', (event) => {
    event.waitUntil(async function() {
        const cache = await caches.open(CACHE_NAME);
        await cache.addAll([
            '/'
        ]);
    }());
});

self.addEventListener('activate', (event) => {
    event.waitUntil(async function() {
        const cache = await caches.open(CACHE_NAME);
        const cacheNames = await cache.keys();
        await Promise.all(
            cacheNames.map(cacheName => caches.delete(cacheName))
        );
    }());
});

self.addEventListener('fetch', (event) => {
    event.respondWith(async function() {
        const networkPromise = fetch(event.request);
        const cachePromise = caches.open(CACHE_NAME);

        try {
            const networkResponse = await networkPromise;
            cachePromise
                .then(cache => {
                    cache.put(event.request, networkResponse);
                });
            return networkResponse.clone();
        } catch (error) {
            const cache = await cachePromise;
            const cacheResponse = await cache.match(event.request);
            return cacheResponse;
        }
    }());
});