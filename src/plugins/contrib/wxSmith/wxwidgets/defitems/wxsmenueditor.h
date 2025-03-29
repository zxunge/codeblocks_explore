/*
* This file is part of wxSmith plugin for Code::Blocks Studio
* Copyright (C) 2006-2007  Bartlomiej Swiecki
*
* wxSmith is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* wxSmith is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with wxSmith. If not, see <http://www.gnu.org/licenses/>.
*
* $Revision$
* $Id$
* $HeadURL$
*/

#ifndef WXSMENUEDITOR_H
#define WXSMENUEDITOR_H

//(*Headers(wxsMenuEditor)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/treectrl.h>
//*)

#include "wxsmenu.h"
#include "wxsmenuitem.h"

class wxsMenuBar;

class wxsMenuEditor: public wxPanel
{
    public:

        /** \brief Ctor for wxsMenuBar */
        wxsMenuEditor(wxWindow* parent,wxsMenuBar* MenuBar);

        /** \brief Ctor for wxsMenu */
        wxsMenuEditor(wxWindow* parent,wxsMenu* Menu);

        /** \brief Dctor */
        virtual ~wxsMenuEditor();

        /** \brief Function applying current edited content into real wxsMenu or wxsMenuBar object */
        void ApplyChanges();

    private:

        typedef wxsMenuItem::Type Type;

        /** \brief Data of menu item
         *
         * This is almost copy of wxMenu's properties, in contains additional
         * pointers to m_Child, m_Next and m_Parent items. Full functionality
         * of wxsMenu was not required here so similar structure containing
         * data only has been provided
         */
        struct MenuItem
        {
            Type      m_Type;
            wxString  m_Variable;
            bool      m_IsMember;
            wxString  m_Id;
            wxString  m_Label;
            wxString  m_Accelerator;
            wxString  m_Help;
            wxsBitmapData m_Bitmap;
            wxString  m_ExtraCode;
            bool      m_Enabled;
            bool      m_Checked;
            wxString  m_HandlerFunction;
            MenuItem* m_Child;
            MenuItem* m_Next;
            MenuItem* m_Parent;

            wxTreeItemId m_TreeId;
        };

        /** \brief Helper class which connects MenuItem to wxTreeItemData
         *
         * This class is required to prevent automatic deletion of MenuItem
         * classes
         */
        class MenuItemHolder: public wxTreeItemData
        {
            public:
                MenuItemHolder(MenuItem* Item): m_Item(Item) {}
                virtual ~MenuItemHolder() {}
                MenuItem* m_Item;
        };

        /** \brief Function with wxSmith's code generating panel's content */
        void CreateContent(wxWindow* parent);

        /** \brief Copying data into internal structures */
        void CreateDataCopy();
        void CreateDataCopyReq(wxsMenuBar* Bar,MenuItem* Parent);
        void CreateDataCopyReq(wxsMenu* Menu,MenuItem* Parent);
        void CreateDataCopyReq(wxsMenuItem* Menu,MenuItem* Parent);

        /** \brief Storing copy of data */
        void StoreDataCopy();
        void StoreDataCopyReq(wxsParent* Parent,MenuItem* Item);

        /** \brief Deleting data copy */
        void DeleteDataCopy();
        void DeleteDataCopyReq(MenuItem* Item);

        /** \brief Updating content of tree and selecting first item */
        void UpdateMenuContent();
        void UpdateMenuContentReq(wxTreeItemId Id,MenuItem* Item);

        /** \brief Checking data consistency */
        void CheckConsistency();
        void CheckConsistencyReq(MenuItem* Item);

        /** \brief Getting name shown in resource tree for given item */
        wxString GetItemTreeName(MenuItem* Item);

        /** \brief Selecting item - this must update current item's data and switch to new one */
        void SelectItem(MenuItem* NewSelection);

        /** \brief Updating item's type and getting set of available properties */
        Type CorrectType(MenuItem* Item,bool& UseId,bool& UseLabel,bool& UseAccelerator,bool& UseHelp,bool& UseEnabled,bool& UseChecked);

        /** \brief Getting previous item in this node */
        MenuItem* GetPrevious(MenuItem* Item);

        wxsMenuBar* m_MenuBar;  ///< \brief Edited menu bar, 0 if editing menu
        wxsMenu*    m_Menu;     ///< \brief Edited menu, 0 if editing menu bar
        MenuItem*   m_First;    ///< \brief First child item od edited resource
        MenuItem*   m_Selected; ///< \brief Currently selected item
        bool        m_BlockSel; ///< \brief Flag for blockig select events from tree ctrl
        bool        m_BlockRead;///< \brief Flag for blocking reading data from dialog to MenuItem

        //(*Identifiers(wxsMenuEditor)
        static const wxWindowID ID_TREECTRL1;
        static const wxWindowID ID_RADIOBUTTON1;
        static const wxWindowID ID_RADIOBUTTON4;
        static const wxWindowID ID_RADIOBUTTON2;
        static const wxWindowID ID_RADIOBUTTON5;
        static const wxWindowID ID_RADIOBUTTON3;
        static const wxWindowID ID_STATICLINE1;
        static const wxWindowID ID_STATICTEXT6;
        static const wxWindowID ID_TEXTCTRL4;
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_TEXTCTRL3;
        static const wxWindowID ID_STATICTEXT4;
        static const wxWindowID ID_CHECKBOX1;
        static const wxWindowID ID_STATICTEXT5;
        static const wxWindowID ID_CHECKBOX2;
        static const wxWindowID ID_STATICLINE2;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON3;
        static const wxWindowID ID_BUTTON4;
        static const wxWindowID ID_BUTTON5;
        static const wxWindowID ID_BUTTON6;
        //*)

        //(*Handlers(wxsMenuEditor)
        void OnContentSelectionChanged(wxTreeEvent& event);
        void OnTypeChanged(wxCommandEvent& event);
        void OnButtonUpClick(wxCommandEvent& event);
        void OnButtonDownClick(wxCommandEvent& event);
        void OnButtonNewClick(wxCommandEvent& event);
        void OnButtonDelClick(wxCommandEvent& event);
        void OnButtonLeftClick(wxCommandEvent& event);
        void OnButtonRightClick(wxCommandEvent& event);
        void OnLabelChanged(wxCommandEvent& event);
        //*)

        //(*Declarations(wxsMenuEditor)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxBitmapButton* BitmapButton4;
        wxButton* Button5;
        wxButton* Button6;
        wxCheckBox* m_Checked;
        wxCheckBox* m_Enabled;
        wxRadioButton* m_TypeBreak;
        wxRadioButton* m_TypeCheck;
        wxRadioButton* m_TypeNormal;
        wxRadioButton* m_TypeRadio;
        wxRadioButton* m_TypeSeparator;
        wxStaticLine* StaticLine1;
        wxStaticLine* StaticLine2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxTextCtrl* m_Accelerator;
        wxTextCtrl* m_Help;
        wxTextCtrl* m_Id;
        wxTextCtrl* m_Label;
        wxTreeCtrl* m_Content;
        //*)

};

#endif
