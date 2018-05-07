module StickyContainer = {
  [@bs.module "react-sticky"]
  external reactClass : ReasonReact.reactClass = "StickyContainer";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Sticky = {
  module RenderProps = {
    [@bs.deriving abstract]
    type t = {
      style: ReactDOMRe.Style.t,
      isSticky: bool,
      wasSticky: bool,
      distanceFromTop: int,
      distanceFromBottom: int,
      calculatedHeight: int,
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~topOffset: int=?,
      ~bottomOffset: int=?,
      ~relative: bool=?,
      ~disableCompensation: bool=?,
      ~disableHardwareAcceleration: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "react-sticky"]
  external reactClass : ReasonReact.reactClass = "Sticky";
  let make =
      (
        ~topOffset: option(int)=?,
        ~bottomOffset: option(int)=?,
        ~relative: option(bool)=?,
        ~disableCompensation: option(bool)=?,
        ~disableHardwareAcceleration: option(bool)=?,
        children: RenderProps.t => ReasonReact.reactElement,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~topOffset?,
          ~bottomOffset?,
          ~relative?,
          ~disableCompensation?,
          ~disableHardwareAcceleration?,
          (),
        ),
      children,
    );
};
