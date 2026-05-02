// Function : FUN_400dae18
// Address  : 0x400dae18
// Size     : 87 bytes


undefined2 FUN_400dae18(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 auStack_38 [4];
  undefined4 auStack_34 [4];
  undefined2 auStack_22 [17];
  
  auStack_22[0] = 0;
  memw();
  memw();
  memw();
  if (*(int *)(param_1 + 0xb0) == 4) {
    auStack_38[0] = param_3;
    auStack_34[0] = param_2;
    func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
    auStack_22[0] = FUN_40184424(param_1);
    iVar1 = FUN_400dad84(param_1,auStack_22,auStack_34,auStack_38);
    if (iVar1 == 0) {
      auStack_22[0] = 0;
    }
    func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  }
  return auStack_22[0];
}

