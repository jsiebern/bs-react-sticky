# Reason bindings for react-sticky
This library provides Reason bindings for
[react-sticky](https://github.com/captivationsoftware/react-sticky).

*These bindings should be complete and working, I use them in production without problems. If, however, you encounter any problems, feel free to open an issue.*

## Installation (for your Reason project)

Run:

    yarn add react-sticky @jsiebern/bs-react-sticky

to add the library to your project dependencies. And add `@jsiebern/bs-react-sticky` to the `bs-dependencies` node of your `bsconfig.json`.

## Example

[See this link for the full example.](https://github.com/jsiebern/bs-react-sticky/blob/master/examples/Example.re)

```reasonml
let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <ReactSticky.StickyContainer>
      <ReactSticky.Sticky>
        ...(
             stickyProps =>
               ReactSticky.Sticky.RenderProps.(
                 <div style=(stickyProps |. style)>
                   ((stickyProps |. isSticky ? "Moving" : "Not Moving") |. ReasonReact.string)
                 </div>
               )
           )
      </ReactSticky.Sticky>
    </ReactSticky.StickyContainer>,
};
```

**Important**: The bindings use an [abstract object type](https://bucklescript.github.io/docs/en/generate-converters-accessors.html#abstract-type), so the easiest thing to access the `stickyProps` is to open `ReactSticky.Sticky.RenderProps` and then access the render functions props by the chain operator (e.g. `stickyProps |. isSticky`).  