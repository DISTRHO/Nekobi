/*
 * DISTRHO Nekobi Plugin, based on Nekobee by Sean Bolton and others.
 * Copyright (C) 2013-2021 Filipe Coelho <falktx@falktx.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the LICENSE file.
 */

#ifndef DISTRHO_UI_NEKOBI_HPP_INCLUDED
#define DISTRHO_UI_NEKOBI_HPP_INCLUDED

#include "DistrhoUI.hpp"

#include "DistrhoArtworkNekobi.hpp"
#include "NekoWidget.hpp"
#include "ImageBaseWidgets.hpp"

#ifdef DGL_CAIRO
typedef DGL_NAMESPACE::CairoImage NekoImage;
#else
typedef DGL_NAMESPACE::OpenGLImage NekoImage;
#endif

typedef DGL_NAMESPACE::ImageBaseAboutWindow<NekoImage> NekoImageAboutWindow;
typedef DGL_NAMESPACE::ImageBaseButton<NekoImage> NekoImageButton;
typedef DGL_NAMESPACE::ImageBaseKnob<NekoImage> NekoImageKnob;
typedef DGL_NAMESPACE::ImageBaseSlider<NekoImage> NekoImageSlider;

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class DistrhoUINekobi : public UI,
                        public NekoImageButton::Callback,
                        public NekoImageKnob::Callback,
                        public NekoImageSlider::Callback,
                        public IdleCallback
{
public:
    DistrhoUINekobi();

protected:
    // -------------------------------------------------------------------
    // DSP Callbacks

    void parameterChanged(uint32_t index, float value) override;

    // -------------------------------------------------------------------
    // Widget Callbacks

    void imageButtonClicked(NekoImageButton* button, int) override;
    void imageKnobDragStarted(NekoImageKnob* knob) override;
    void imageKnobDragFinished(NekoImageKnob* knob) override;
    void imageKnobValueChanged(NekoImageKnob* knob, float value) override;
    void imageSliderDragStarted(NekoImageSlider* slider) override;
    void imageSliderDragFinished(NekoImageSlider* slider) override;
    void imageSliderValueChanged(NekoImageSlider* slider, float value) override;

    void onDisplay() override;

    // -------------------------------------------------------------------
    // Other Callbacks

    void idleCallback() override;

private:
    NekoImage            fImgBackground;
    NekoImageAboutWindow fAboutWindow;
    NekoWidget           fNeko;

    ScopedPointer<NekoImageButton> fButtonAbout;
    ScopedPointer<NekoImageSlider> fSliderWaveform;
    ScopedPointer<NekoImageKnob> fKnobTuning, fKnobCutoff, fKnobResonance;
    ScopedPointer<NekoImageKnob> fKnobEnvMod, fKnobDecay, fKnobAccent, fKnobVolume;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistrhoUINekobi)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // DISTRHO_UI_NEKOBI_HPP_INCLUDED
