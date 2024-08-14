# Net Banking Application

This Java Swing application simulates a simple net banking interface where users can validate a PIN, enter an amount, and simulate payment actions. The application provides basic functionality for validating inputs, handling errors, and updating the user interface dynamically.

## Features

- **PIN Validation**: Checks if the entered PIN is a 4-digit numeric value.
- **Amount Validation**: Ensures the entered amount is a numeric value.
- **Submit Button**: Displays an error message indicating a system update is required.
- **Update Button**: Simulates system update by replacing the submit button with a new payment button.
- **New Pay Button**: Shows a success message indicating a successful payment after the system update.

## Components

- **JFrame**: Main window containing all UI elements.
- **JLabel**: Labels for PIN and amount fields.
- **JTextField**: Input fields for entering PIN and amount.
- **JButton**: Buttons for validation, payment submission, and updating the system.
- **JOptionPane**: Dialog boxes for displaying messages and errors.

## Code Overview

1. **Main Frame (`JFrame`)**:
   - Title: "Net Banking"
   - Layout: Null layout for manual positioning of components

2. **UI Components**:
   - **Labels**: Prompts for PIN and amount input
   - **Text Fields**: Inputs for PIN and amount
   - **Buttons**: Validate, Pay, and Update

3. **Event Handlers**:
   - **Validate Button** (`chk`): Validates the PIN and amount. Shows a message with entered values or an error message if inputs are invalid.
   - **Submit Button** (`submit`): Displays an error message indicating a system update is needed.
   - **Update Button** (`update`): Simulates system update by replacing the submit button with a new "NEW PAY" button.

4. **Utility Method**:
   - `num(String str)`: Checks if the provided string is numeric.

## Compilation and Execution

1. Save the code in a file named `bank.java`.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `bank.java`.
4. Compile the code using `javac`:
   ```bash
   javac bank.java
