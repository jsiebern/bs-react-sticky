let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div style=(ReactDOMRe.Style.make(~height="3000px", ()))>
      <ReactSticky.StickyContainer>
        <div style=(ReactDOMRe.Style.make(~height="100px", ~backgroundColor="green", ()))>
          ("Not Sticky" |. ReasonReact.string)
        </div>
        <ReactSticky.Sticky topOffset=100>
          ...(
               stickyProps =>
                 ReactSticky.Sticky.RenderProps.(
                   <div style=(stickyProps |. style)>
                     <div style=(ReactDOMRe.Style.make(~height="100px", ~backgroundColor="red", ()))>
                       ("Sticky" |. ReasonReact.string)
                       <br />
                       ((stickyProps |. isSticky ? "Moving" : "Not Moving") |. ReasonReact.string)
                     </div>
                   </div>
                 )
             )
        </ReactSticky.Sticky>
        <div style=(ReactDOMRe.Style.make(~height="100px", ~backgroundColor="green", ()))>
          ("Not Sticky" |. ReasonReact.string)
        </div>
      </ReactSticky.StickyContainer>
    </div>,
};
