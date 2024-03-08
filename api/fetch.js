const fetch = require("node-fetch");
const fs = require("fs");

const fetchData = async (query) => {
  const API_URL = `https://api.calorieninjas.com/v1/nutrition?query=${query}`;
  const API_KEY = "yuYmYaFd385QP2Hda4JHwQ==c08UhxL8MWJGxcgM";

  const headers = new Headers();
  headers.append("X-Api-Key", API_KEY);

  try {
    const response = await fetch(API_URL, {
      method: "GET",
      headers: headers,
    });
    const data = await response.json();
    return data;
  } catch (e) {
    console.log(e);
  }
};

const query = process.argv[2];

if (!query) {
  console.log("Usage: node fetch.js <query>");
  process.exit(1);
}

const writeData = (data) => {
  fs.writeFile("../macros/db/apiResult.json", JSON.stringify(data, null, 2), (err) => {
    if (err) {
      console.error("Error writing data to file:", err);
    } else {
      console.log("Data has been written to ../db/apiResult.json");
    }
  });
};

// Example usage:
fetchData(query).then((data) => writeData(data));
