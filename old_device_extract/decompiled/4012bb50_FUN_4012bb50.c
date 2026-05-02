// Function : FUN_4012bb50
// Address  : 0x4012bb50
// Size     : 87 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012bb50(int param_1,undefined4 param_2)

{
  int unaff_retaddr;
  int in_a13;
  int *in_t0;
  
  func_0x4013495c();
  in_a13 = in_a13 * 8;
  unaff_retaddr = -unaff_retaddr;
  cust0();
  memw();
  *(undefined4 *)(in_a13 + unaff_retaddr + 0xdc) = 0;
  memw();
  FUN_4014098c();
  FUN_401409dc(in_a13 + unaff_retaddr,*(int *)(param_1 + 0x44) + 0x398);
  FUN_40140b04(in_a13 + unaff_retaddr,param_2);
  _DAT_160a4df4 = 0x30;
  memw();
  FUN_401409a0(in_a13 + unaff_retaddr);
  memw();
  memw();
  if (*(int *)(in_a13 + unaff_retaddr + 0xdc) != *in_t0) {
    (*(code *)&SUB_40082ec4)();
  }
  return;
}

