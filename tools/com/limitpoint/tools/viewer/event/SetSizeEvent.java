
//
// Copyright (c) 2014 Limit Point Systems, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

package com.limitpoint.tools.viewer.event;

import com.limitpoint.tools.viewer.render.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * setting the size of the render window.
 *
 */
public class SetSizeEvent extends RenderThreadEvent
{
  /**
   * The width
   */
  protected int width;

  /**
   * The height
   */
  protected int height;

  /**
   * The constructor
   */
  public SetSizeEvent(int xwidth, int xheight)
  {
    width = xwidth;
    height = xheight;
  }

  /**
   * Handle this <code>SetSizeEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    xrenderThread.setSize(width, height);
  }
}