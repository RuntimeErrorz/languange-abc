btn.addEventListener("click", () => {
  alert("You clicked me!");

  let pElem = document.createElement("p");
  pElem.textContent = "This is a newly-added paragraph.";
  document.body.appendChild(pElem);
});
