// Function : FUN_4013cf6c
// Address  : 0x4013cf6c
// Size     : 64 bytes


undefined4
FUN_4013cf6c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_401866a8(param_1);
  uVar3 = 0xffffffe0;
  if (iVar2 != 0) {
    func_0x4013cf40();
    memw();
    param_1[1] = 0;
    memw();
    uVar1 = FUN_401687e8(param_1 + 2,*param_1,param_2);
    memw();
    param_1[1] = uVar1;
    memw();
    uVar3 = FUN_4013cee0(param_1,param_3,param_4);
    FUN_4013cf58();
  }
  return uVar3;
}

