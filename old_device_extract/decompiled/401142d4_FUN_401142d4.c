// Function : FUN_401142d4
// Address  : 0x401142d4
// Size     : 60 bytes


uint FUN_401142d4(int param_1,int param_2,undefined1 param_3,int param_4)

{
  if (0x80 < (uint)(param_4 + 2 + param_1)) {
    (*(code *)&SUB_40094c54)("ONS_LEN",0x6f1,"on_byte","/dhcp.c");
  }
  *(undefined1 *)(param_2 + param_1) = param_3;
  *(char *)(param_2 + (param_1 + 1U & 0xffff)) = (char)param_4;
  memw();
  memw();
  return param_1 + 2U & 0xffff;
}

