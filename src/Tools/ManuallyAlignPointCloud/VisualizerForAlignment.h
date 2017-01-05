// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2015 Qianyi Zhou <Qianyi.Zhou@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <thread>
#include <Core/Core.h>
#include <IO/IO.h>
#include <Visualization/Visualization.h>

namespace three {

class VisualizerForAlignment : public Visualizer
{
public:
	VisualizerForAlignment(const VisualizerWithEditing &source,
			const VisualizerWithEditing &target, double voxel_size = -1.0,
			bool with_scaling = true, bool use_dialog = true) :
			source_visualizer_(source), target_visualizer_(target) :
			voxel_size_(voxel_size), with_scaling_(with_scaling),
			use_dialog_(use_dialog) {}
	~VisualizerForAlignment() override {}

public:
	void PrintVisualizerHelp() override;

protected:
	void KeyPressCallback(GLFWwindow *window, int key, int scancode, int action,
			int mods) override;

private:
	const VisualizerWithEditing &source_visualizer_;
	const VisualizerWithEditing &target_visualizer_;
	double voxel_size_ = -1.0;
	bool with_scaling_ = true;
	bool use_dialog_ = true;
};

}		// namespace three