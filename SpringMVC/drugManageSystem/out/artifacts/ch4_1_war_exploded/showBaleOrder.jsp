<%@ page import="beans.Staff" %>
<%@ page import="beans.BuyBill" %>
<%@ page import="java.util.List" %>
<%--
  Created by IntelliJ IDEA.
  User: beauw
  Date: 2018/1/6
  Time: 12:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>进货单管理页面</title>
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/master.css">
    <style type="text/css">
        ul.nav li:nth-child(4) a{
            background-color: #a89b9b;
            color: #f8f8f8;
        }
        .yourcontainer{
            padding-bottom: 20px;
        }
        #noshow {
            display: none;
        }
    </style>
</head>
<body>
<!-- 顶部状态栏 -->
<div class="navbar navbar-default">
    <div class="container-fluid">
        <div class="navbar-header">
            <a href="" class="navbar-brand">药品后台管理</a>
        </div>

        <p class="navbar-text">当前登录用户</p>
        <p class="navbar-text">
            <%
                Staff staff = (Staff) session.getAttribute("staff");
                out.println(staff.getName());
            %>
        </p>
        <p class="navbar-text navbar-right"></p>
        <a href="managermaster?id=11" type="button" class="btn btn-default navbar-btn navbar-right">退出</a>    </div>
</div>
<!-- 左侧导航 -->
<div class="navbox">
    <ul class="nav">
        <li><a href="managermaster?id=1">管理主页</a></li>
        <li><a href="managermaster?id=2">员工管理</a></li>
        <li><a href="managermaster?id=3">查看库存</a></li>
        <li><a href="managermaster?id=4">查看进货</a></li>
        <li><a href="managermaster?id=5">查看售货</a></li>
        <li><a href="managermaster?id=6">查看退厂</a></li>
        <li><a href="managermaster?id=7">查看客户</a></li>
        <li><a href="managermaster?id=8">查看厂商</a></li>
    </ul>
</div>

<div class="mainArea">
    <div class="showArea">

        <div class="yourcontainer">

            <form class="form-inline" action="searchbytime">

                <div class="form-group">
                    <label for="exampleInputEmail3" class="control-label">初始日期</label>
                    <input type="text" name="id" value="1" id="noshow">
                    <input type="date" class="form-control" id="exampleInputEmail3" name="startdate" value="2017-06-02">
                </div>
                <div class="form-group">
                    <label for="exampleInputEmail3" class="control-label">截至日期</label>
                    <input type="date" class="form-control" id="exampleInputPassword3" name="stopdate" value="2017-11-17">
                </div>
                <input type="submit" class="btn btn-primary" value="查询">
            </form>
        </div>

        <table class="table table-bordered table-striped" id="t_customer">
            <tr>
                <th>序号</th>
                <th>BUYRECORDID</th>
                <th>DATE</th>
                <th>TIME</th>
                <th>厂家名</th>
                <th>BUYER</th>
                <th>操作</th>

            </tr>
            <%
                List<BuyBill> list = (List<BuyBill>) session.getAttribute("balelist");
                int i = 1;
                for (BuyBill mybalelist:list) {
            %>
            <tr>
                <td><%= i++ %></td>
                <td><%= mybalelist.getBuyBillID()%></td>
                <td><%= mybalelist.getDate()%></td>
                <td><%=mybalelist.getTime() %></td>
                <td><%= mybalelist.getProducerName() %></td>
                <td><%=mybalelist.getBuyerName() %></td>
                <td><a href="detailorder?s=0&b=<%=mybalelist.getBuyBillID()%>" type="button" class="btn btn-info btn-xs btn-block">查看详细</a></td>
            </tr>
            <%
                }
            %>
        </table>
    </div>
</div>

<script src="bootstrap/js/jquery.min.js" charset="utf-8"></script>
<script src="bootstrap/js/bootstrap.min.js" charset="utf-8"></script>

</body>
</html>
