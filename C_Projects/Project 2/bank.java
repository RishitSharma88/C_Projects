import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

class bank 
{
    public static void main(String[] args) 
	{
        JFrame f1 = new JFrame("Net Banking");
        JLabel pin = new JLabel("Enter the 4 digit pin:");
        JTextField p = new JTextField(4); // Set columns for the text field
        JLabel amt = new JLabel("Enter the amount to be paid:");
        JTextField a = new JTextField(4);
        JButton chk = new JButton("VALIDATE");
        JButton submit = new JButton("PAY");
        JButton update = new JButton("UPDATE");
        
        // Set layout manager to null
        f1.setLayout(null);

        // Set bounds for each component
        pin.setBounds(50, 50, 200, 30); // x, y, width, height
        p.setBounds(50, 80, 100, 30);
        amt.setBounds(50, 120, 200, 30);
        a.setBounds(50, 150, 100, 30);
        chk.setBounds(50, 200, 100, 30);
        submit.setBounds(50, 250, 100, 30);
        update.setBounds(160, 250, 100, 30);
        
        // Add components to the frame
        f1.add(pin);
        f1.add(p);
        f1.add(amt);
        f1.add(a);
        f1.add(chk);
        f1.add(submit);
        f1.add(update);
        
        // Set the frame properties
        f1.setSize(500, 500);
        f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f1.setVisible(true);

        // Add ActionListener to the chk button
        chk.addActionListener(new ActionListener() 
		{
            public void actionPerformed(ActionEvent e) 
			{
                String inpin = p.getText();
                String amount = a.getText();
                try 
				{
                    if (!num(inpin) || inpin.length() != 4) 
					{
                        throw new IOException("Invalid PIN. Please enter a 4 digit number.");
                    }
                    if (!num(amount)) 
					{
                        throw new IOException("Invalid amount. Please enter a numeric value.");
                    }
                    // If no exception is thrown, display the entered values
                    JOptionPane.showMessageDialog(f1, "PIN: " + inpin + "\nAmount: " + amount);
                } catch (IOException ex) 
				{
                    // Show error message in a dialog box
                    JOptionPane.showMessageDialog(f1, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        // Add ActionListener to the submit button
        submit.addActionListener(new ActionListener() 
		{
            public void actionPerformed(ActionEvent e) 
			{
                JOptionPane.showMessageDialog(f1, "Some Error occurred. Please update the system.", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
		
        // Add ActionListener to the update button
        update.addActionListener(new ActionListener() 
		{
            public void actionPerformed(ActionEvent e) 
			{
                JOptionPane.showMessageDialog(f1, "Updated the system", "Updated", JOptionPane.INFORMATION_MESSAGE);

                // Remove the old submit button
                f1.remove(submit);
                f1.repaint(); // Repaint the frame to reflect changes

                // Create and add a new working button
                JButton newButton = new JButton("NEW PAY");
                newButton.setBounds(50, 250, 100, 30); // Set position for the new button
                f1.add(newButton);

                // Add ActionListener to the new button
                newButton.addActionListener(new ActionListener() 
				{
                    public void actionPerformed(ActionEvent e) 
					{
                        JOptionPane.showMessageDialog(f1, "Payment Successful!", "Payment Successful Screen", JOptionPane.INFORMATION_MESSAGE);
                    }
                });

                // Revalidate the frame layout to ensure new components are properly arranged
                f1.revalidate();
            }
        });
    }

    // Method to check if a string is numeric
    static boolean num(String str) 
	{
        if (str == null || str.isEmpty()) 
		{
            return false;
        }
        for (char c : str.toCharArray()) 
		{
            if (!Character.isDigit(c)) 
			{
                return false;
            }
        }
        return true;
    }
}
