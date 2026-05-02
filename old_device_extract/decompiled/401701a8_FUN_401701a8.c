// Function : FUN_401701a8
// Address  : 0x401701a8
// Size     : 67 bytes


undefined4 FUN_401701a8(code *param_1,int param_2)

{
  (*param_1)();
  (*(code *)&SUB_40094bc8)();
  FUN_40170020(param_1);
  (*(code *)&SUB_40094bc8)();
  FUN_4017007c();
  if (param_2 != -1) {
    FUN_401710dc(param_1);
  }
  FUN_4016ff68();
  cust0();
  memw();
  memw();
  return *(undefined4 *)param_1;
}

