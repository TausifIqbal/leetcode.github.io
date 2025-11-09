// Wait for the HTML document to be fully loaded
document.addEventListener("DOMContentLoaded", () => {

    // --- 1. DATA ---
    // (Your original solutions object)
    const solutions = {
        DP: [
            { title: "Climbing Stairs (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/climbing_stairs.cpp" },
            { title: "Number of digit one (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/number_of_digit_one.cpp" },
            { title: "Minimum skips to arrive at meeting (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/min_skips_to_arrive_at_meeting.cpp" },
            { title: "Minimum time to finish all jobs (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/min_time_to_finish_all_job.cpp" },
            { title: "Count special Integers (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/count_special_integers.cpp" },
            { title: "Numbers at most N given digit set (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/numbers_at_most_n_given_digit_set.cpp" },
            { title: "Merge stones (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/merge_stone.cpp" },
            { title: "Cut stick (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/min_cost_to_cut_a_stick.cpp" },
        ],
        Array: [
            { title: "Minimum in sorted array (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/minimum_in_sorted_array.cpp" },
            { title: "Maximum Length of a contiguous array (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/contiguous_array.cpp" },
            { title: "Container with most Water  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/container_with_most_water.cpp" },
            { title: "K pair with smallest sum  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/k_pair_with_smallest_sum.cpp" },
            { title: "Duplicate Number  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/duplicate_number.cpp" },
            { title: "Happy Number  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/happy_number.cpp" },
            { title: "Number of visible people in a queue  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/number_of_visible_people_in_a_queue.cpp" },
            { title: "Pattern 132  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/pattern_132.cpp" },
        ],
        SlidingWindow: [
            { title: "Median in sliding window  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/median_in_sliding_window.cpp" },
            { title: "Sliding window max  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/sliding_window_max.cpp" },
        ],
        Heap: [
            { title: "Median from data stream  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/median_from_data_stream.cpp" },
            { title: "IPO  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/ipo.cpp" },
            { title: "Task Scheduler  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/task-sheduler.cpp" },
        ],
        Graph: [
            { title: "Number of Islands  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/number_of_islands.cpp" },
            { title: "Clone graphs  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/clone_graph.cpp" },
        ],
        Node: [
            { title: "Reverse Node  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/reverse_node.cpp" },
            { title: "Swap nodes in pair  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/swap_node_pair.cpp" },
        ],
        Binary_Search: [
            { title: "Koko eating banana (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/koko_eating_bananas.cpp" },
            { title: "Heater (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/heater.cpp" },
            { title: "Maximum number of robot within budget (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/max_num_of_robot_within_budget.cpp" },
        ],
        String: [
            { title: "Minimum window Substring (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/minimum_window_substring.cpp" },
        ],
        Trie: [
            { title: "Sum of prefix of string (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/sum_of_prefix_of_string.cpp" },
            { title: "Maximum strong pair xor (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/solutions/maximum_strong_pair_xor.cpp" },
        ],
        OOO: [
            { title: "Banking System  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/banking_system.cpp" },
            { 
		    title: "Banking System  (C++)", 
		    link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/banking_system.cpp",
		    diagram: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/banking_system.png"
	    },
            { title: "Parking Lot System with multiple floors  (C++)", link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/parking_lot_system_v2.cpp" },
            { 
		    title: "Parking Lot System with multiple floors  (C++)",
		    link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/parking_lot_system_v2.cpp",
		    diagram: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/parking_lot.png"
	    },
            { 
			title: "Vending Machine  (C++)", 
			link: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/vending_machine.cpp",
			diagram: "https://raw.githubusercontent.com/TausifIqbal/Leetcode/main/OOO/vending_machine_uml.png"
	    },

        ]
    };

    // --- 2. STATE ---
    let currentItems = [];
    let currentIndex = -1;

    // --- 3. DOM ELEMENTS ---
    const mainContent = document.getElementById("mainContent");
    const categoryList = document.getElementById("categoryList");

    // --- 4. FUNCTIONS ---
    function showSolutions(category) {
        mainContent.innerHTML = `<h1>${category} Solutions</h1>`;
        setActiveCategory(category);

        if (category === "All") {
            currentItems = [];
            Object.keys(solutions).forEach(cat => {
                currentItems = currentItems.concat(solutions[cat].map(sol => ({ ...sol, cat })));
            });
        } else {
            currentItems = solutions[category] ? solutions[category].map(sol => ({ ...sol, cat: category })) : [];
        }

        if (currentItems.length === 0) {
            mainContent.innerHTML += `<p>No solutions yet in ${category}.</p>`;
            return;
        }

        const ul = document.createElement("ul");
        currentItems.forEach((sol, index) => {
            const li = document.createElement("li");
            // We use onclick here because these elements are dynamically created.
            // A more advanced way is event delegation on the 'ul', but this is fine.
            li.innerHTML = `<a onclick="loadFile(${index})">${sol.title}</a> <small>(${sol.cat})</small>`;
            ul.appendChild(li);
        });
        mainContent.appendChild(ul);
    }
// Must be on the 'window' object to be callable from dynamic 'onclick'
    window.loadFile = function(index) {
        currentIndex = index;
        const sol = currentItems[index];
        mainContent.innerHTML = `<h1>${sol.title}</h1><p>Loading...</p>`;

        let diagramHtml = '';
        let codeHtml = '';

        // 1. Prepare Diagram HTML (if it exists)
        if (sol.diagram) {
            diagramHtml = `
                <h2>Design Diagram</h2>
                <img src="${sol.diagram}" alt="${sol.title} Diagram" 
                     style="width: 100%; max-width: 800px; border: 1px solid var(--border-color); border-radius: var(--border-radius); margin-bottom: var(--spacing-lg);">
            `;
        }

        // 2. Prepare Code Fetching Promise (if it exists)
        let codeFetchPromise;
        if (sol.link) {
            codeFetchPromise = fetch(sol.link)
                .then(response => {
                    if (!response.ok) {
                        throw new Error(`HTTP error! status: ${response.status}`);
                    }
                    return response.text();
                })
                .then(data => {
                    // Escape HTML characters
                    const escapedData = data.replace(/</g, "&lt;").replace(/>/g, "&gt;");
                    codeHtml = `
                        <h2>Code</h2>
                        <pre><code class="language-cpp">${escapedData}</code></pre>
                    `;
                })
                .catch(err => {
                    console.error("Failed to load code:", err);
                    codeHtml = `<h2>Code</h2><p style="color:red;">Failed to load code file.</p>`;
                });
        } else {
            // If no code link, just create a resolved promise
            codeFetchPromise = Promise.resolve();
        }

        // 3. When code (if any) is fetched, render everything
        codeFetchPromise.then(() => {
            mainContent.innerHTML = `
                <h1>${sol.title}</h1>
                
                ${diagramHtml}
                
                ${codeHtml}

                <div class="nav-buttons">
                    <button onclick="prevFile()" ${index === 0 ? "disabled" : ""}>⬅ Prev</button>
                    <button onclick="nextFile()" ${index === currentItems.length - 1 ? "disabled" : ""}>Next ➡</button>
                </div>
            `;
            
            // Only run highlight.js if there was code to highlight
            if (sol.link) {
                hljs.highlightAll();
            }
        });
    }

    // Must be on 'window' to be callable from dynamic 'onclick'
    window.prevFile = function() {
        if (currentIndex > 0) {
            loadFile(currentIndex - 1);
        }
    }

    // Must be on 'window' to be callable from dynamic 'onclick'
    window.nextFile = function() {
        if (currentIndex < currentItems.length - 1) {
            loadFile(currentIndex + 1);
        }
    }

    function setActiveCategory(category) {
        // Remove 'active' from all links
        categoryList.querySelectorAll('a').forEach(link => {
            link.classList.remove('active');
        });
        // Add 'active' to the matching link
        const activeLink = categoryList.querySelector(`a[data-category="${category}"]`);
        if (activeLink) {
            activeLink.classList.add('active');
        }
    }

    // --- 5. EVENT LISTENERS ---
    categoryList.addEventListener('click', (event) => {
        // Check if the clicked element is an <a> tag
        if (event.target.tagName === 'A') {
            event.preventDefault(); // Stop the link from navigating
            const category = event.target.dataset.category;
            if (category) {
                showSolutions(category);
            }
        }
    });

    // --- 6. INITIALIZATION ---
    // Show 'All' solutions by default on page load
    showSolutions('All');
});
