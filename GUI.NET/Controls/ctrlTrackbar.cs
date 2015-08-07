﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mesen.GUI.Controls
{
	public partial class ctrlTrackbar : UserControl
	{
		public event EventHandler ValueChanged
		{
			add { trackBar.ValueChanged += value; }
			remove { trackBar.ValueChanged -= value; }
		}

		public ctrlTrackbar()
		{
			InitializeComponent();
		}

		public string Caption
		{
			get { return lblText.Text; }
			set { lblText.Text = value; }
		}

		public int Value
		{
			get { return trackBar.Value; }
			set
			{
				trackBar.Value = value;
				txtValue.Text = trackBar.Value.ToString() + "%";
			}
		}

		private void trackBar_ValueChanged(object sender, EventArgs e)
		{
			txtValue.Text = trackBar.Value.ToString() + "%";
		}
	}
}