// Tabs Sorter by Gabriela Aguilar 2023 - Back End

chrome.tabs.query({currentWindow: true}, tabs => // Just access to tabs on the current Window
  {
  const tabList = document.getElementById('tabList'); // Access to the ID of each tab - This will become the list
  tabs.forEach(tab =>
    {
    const listTab = document.createElement('li'); // Makes each ID into a li element for the <ul> in popup.html
    const link = document.createElement('a'); // Makes each li element into a shortcut for the currently opened tab

    link.textContent = tab.title || tab.url; // The text on the list will be exacltly how the Tab's html present 
    link.href = '#'; // Set a placeholder href
    link.addEventListener('click', event => {
      event.preventDefault(); // Prevent default link behavior
      activateTab(tab.id);
    });

    listTab.appendChild(link);
    tabList.appendChild(listItem);
  });
});

function activateTab(tabId) {
  chrome.tabs.update(tabId, { active: true });
  window.close(); // Close the popup after activating the tab
}