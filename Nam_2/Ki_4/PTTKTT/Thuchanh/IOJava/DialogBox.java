/*********************************
  This code originally created by
  the CS181 team was modified by
  Simeon on Jan 17 1999. For further
  info mailto:simeoncran@acm.org
  - 17 Jan 1999 -
  Modified for Swing 21 July 1999
**********************************/

 

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
Creates request and warn dialog boxes.
*/

public class DialogBox extends JFrame implements ActionListener {

	// instance variables
	private JTextField theInput = new JTextField(25);
	private JButton ok = new JButton("OK");
	private boolean ready = false;

	// class variables
	private static boolean inputRequested;

	public static String request (String requestMessage) {
		// request dialog box with no initial prompt
		inputRequested = true;
		DialogBox rdb = new DialogBox
				("Request Dialog Box", requestMessage);
		String inputData = rdb.getString();
		rdb.dispose();
		return inputData;
	}

	public static String request (String requestMessage, String prompt) {
		// request dialog box with an initial request
		inputRequested = true;
		DialogBox rdb = new DialogBox
				("Request Dialog Box", requestMessage, prompt);
		rdb.theInput.setCaretPosition(prompt.length());
		String inputData = rdb.getString();
		rdb.dispose();
		return inputData;
	}

	public static int requestInt (String requestMessage) {
		// request dialog box with no initial prompt; returns int
		boolean failed = true;
		int inputInt = 0;
		String inputData = null;
		do {
			inputRequested = true;
			DialogBox rdb = new DialogBox
					("Request Dialog Box", requestMessage);
			inputData = rdb.getString();
			rdb.dispose();
			try {
				inputInt = Integer.parseInt(inputData);
				failed = false;
			} catch(Exception e) {
					DialogBox.warn("An integer has not been supplied. Try again.");
				}
		} while (failed);
		return inputInt;
	}

	public static double requestDouble (String requestMessage) {
		// request dialog box with no initial prompt; returns double
		boolean failed = true;
		double inputNum = 0;
		String inputData = null;
		do {
			inputRequested = true;
			DialogBox rdb =
		    new DialogBox("Request Dialog Box", requestMessage);
			inputData = rdb.getString();
			rdb.dispose();
			try {
				inputNum = Double.valueOf(inputData).doubleValue();
				failed = false;
			} catch(Exception e) {
					DialogBox.warn("A number has not been supplied. Try again.");
				}
		} while (failed);
		return inputNum;
	}

	public static void warn (String warnMessage) {
		// warn dialog box
		inputRequested = false;
		DialogBox wdb = new DialogBox("Message Box", warnMessage);
		wdb.waitForData();
		wdb.dispose();
	}

	public DialogBox(String boxType, String boxMessage) {
		// constructor if no initial prompt
		super(boxType);
		setBounds(410, 260, 400, 100);
		Toolkit tk = Toolkit.getDefaultToolkit();
		Image im = tk.getImage(getClass().getResource("jim.gif"));
		setIconImage(im);
		JPanel p = new JPanel();
		p.add(new JLabel(boxMessage));
		if (inputRequested) {
			p.add(theInput);
			theInput.addActionListener(this);
		}
		ok.addActionListener(this);
		p.add(ok);
		setContentPane(p);
		setVisible(true);
	}

	public DialogBox(String boxType, String boxMessage, String prompt) {
		// constructor if there is an initial prompt
		super(boxType);
		setBounds(410, 260, 400, 100);
		Toolkit tk = Toolkit.getDefaultToolkit();
		Image im = tk.getImage(getClass().getResource("jim.gif"));
		setIconImage(im);
		JPanel p = new JPanel();
		p.add(new JLabel(boxMessage));
		if (inputRequested) {
			theInput = new JTextField(prompt, 25);
			theInput.addActionListener(this);
			theInput.requestFocus();
			p.add(theInput);
		}
		ok.addActionListener(this);
		p.add(ok);
		setContentPane(p);
		setVisible(true);
	}

	synchronized public void actionPerformed (ActionEvent e) {
			ready = true;
			notifyAll();
	}

	public boolean dataReady () {
		return ready;
	}

	public String getString () {
		waitForData();	// Block until data is ready
		return theInput.getText();
	}

	synchronized public void waitForData()  {
		if (!ready) {
			try {
				wait();
			} catch(Exception e) {}
		}
	}
}