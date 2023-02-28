package controller;

import java.awt.AWTEvent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class ChooseCourseToAttend extends JFrame implements ActionListener {
    JPanel contain;
    JButton submit;
    JLabel courseId, courseName;
    JTextField idt, namet;
    String id;

    public ChooseCourseToAttend(String id) {
        super("选择课程");
        this.id = id;
        setSize(400, 400);
        setLocation(600, 400);
        contain = new JPanel();
        contain.setLayout(null);
        courseId = new JLabel("课程号");
        courseName = new JLabel("课程名");
        submit = new JButton("提交");
        idt = new JTextField();
        namet = new JTextField();
        courseId.setBounds(42, 35, 75, 35);
        idt.setBounds(80, 35, 150, 35);
        courseName.setBounds(40, 90, 75, 35);
        namet.setBounds(80, 90, 150, 35);
        submit.setBounds(102, 320, 70, 30);
        contain.add(courseId);
        contain.add(idt);
        contain.add(courseName);
        contain.add(namet);
        contain.add(submit);
        submit.addActionListener(this);
        add(contain);
        setVisible(true);
        enableEvents(AWTEvent.WINDOW_EVENT_MASK);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submit) {
            if (idt.getText().equals("") || namet.getText().equals("")) {
                JOptionPane.showMessageDialog(null, "信息不能为空！", "提示", JOptionPane.INFORMATION_MESSAGE);
                return;
            }
            String coursename = "";
            String file = System.getProperty("user.dir") + "/data/course.txt";
            String AddedContent = "";
            try {
                String s;
                if (!new File(file).exists()) {
                    JOptionPane.showMessageDialog(null, "课程文件丢失，请联系你的管理员！", "提示", JOptionPane.INFORMATION_MESSAGE);
                    return;
                }
                try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                    int flag = 0;
                    while ((s = br.readLine()) != null) {
                        String[] result = s.split(" ");
                        if (result[0].equals(idt.getText())) {
                            if (!namet.getText().equals(result[1])) {
                                JOptionPane.showMessageDialog(null, "课程名错误！", "提示", JOptionPane.INFORMATION_MESSAGE);
                                return;
                            } else {
                                flag = 1;
                                coursename = result[1];
                                AddedContent += (result[0] + " ");
                                AddedContent += (result[1] + " ");
                            }
                            br.close();
                            break;
                        }
                    }
                    if (flag == 0) {
                        JOptionPane.showMessageDialog(null, "课程不存在", "提示", JOptionPane.INFORMATION_MESSAGE);
                        return;
                    }
                }
            } catch (Exception e1) {
                e1.printStackTrace();
            }
            AddedContent += (id + " ");
            file = System.getProperty("user.dir") + "\\data\\course_student\\" + coursename + "_student.txt";
            if (new File(file).exists()) {
                try {
                    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                        String s = null;
                        while ((s = br.readLine()) != null) {
                            String[] result = s.split(" ");
                            if (result[2].equals(id)) {
                                JOptionPane.showMessageDialog(null, "不能重复选课！", "提示", JOptionPane.INFORMATION_MESSAGE);
                                return;
                            }
                        }
                        br.close();
                    }
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
            // 序号 coursename studentid name gender birthday insi major
            file = System.getProperty("user.dir") + "/data/student.txt";
            try {
                BufferedReader br = new BufferedReader(new FileReader(file));
                String s = null;
                while ((s = br.readLine()) != null) {
                    String[] result = s.split(" ");
                    if (result[0].equals(id))
                        for (int i = 2; i <= 6; ++i)
                            AddedContent += (result[i] + " ");
                }
                br.close();
            } catch (Exception e1) {
                e1.printStackTrace();
            }
            file = System.getProperty("user.dir") + "\\data\\course_student\\" + coursename + "_student.txt";
            try {
                AddedContent = AddedContent.strip();
                BufferedWriter bw = new BufferedWriter(new FileWriter(file, true));
                bw.write(AddedContent);
                bw.newLine();
                bw.close();
            } catch (IOException e2) {
                e2.printStackTrace();
            }
            JOptionPane.showMessageDialog(null, "选课成功", "提示", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    @Override
    public void processWindowEvent(WindowEvent e) {
        if (e.getID() == WindowEvent.WINDOW_CLOSING) {
            this.dispose();
            setVisible(false);
        }
    }
}
