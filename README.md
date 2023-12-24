# todo161
A simple to-do list app in Qt, made for an Object Oriented Programming class project.

<img width="505" alt="Screenshot 2023-12-03 at 5 06 05 PM" src="https://github.com/kyleawayan/todo161/assets/56655579/6d4a2bd7-4cd6-471b-9bff-3ae6d998b281">

## Features
- Simple and reactive UI.
- Large display of remaining items shows how many tasks and events are left at an easy glance.
- Create to-do items.
- Create events, which feature a live countdown until the event.
- Mark tasks as completed to remove them from the list.
- Batch mark multiple tasks as completed.

## How does it work?
Object-oriented programming concepts are used throughout this app. Other than the Qt widgets, managing the to-do list, single to-do list items, and events are the main three objects.

To summarize the structure of these three objects, the `Action` class is created. This stores simple things such as the name of the action and ID. Another class called `Event` is created. `Event` inherits from `Action`, with the additional methods of setting a timestamp.

A class called `Todo` manages the `Action` and `Event` objects. In addition to storing a vector of these objects, there are methods to manage the vector of objects, such as deleting them or retrieving an object based on its ID.

## Development
Qt Creator is required. Loading the project into Qt Creator is all that is needed to develop on the project.

This project was developed on Qt Creator 12.0.0.
