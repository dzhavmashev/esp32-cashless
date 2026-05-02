// Function : FUN_40139bb0
// Address  : 0x40139bb0
// Size     : 60 bytes


undefined4
FUN_40139bb0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_24 [9];
  
  if ((*param_1 == 0) ||
     (auStack_24[0] = param_4, iVar1 = FUN_40139b04(param_2,auStack_24), iVar1 != 0)) {
    uVar2 = 0xffffc180;
  }
  else {
    uVar2 = 0xffffc100;
    if (*(code **)(*param_1 + 0x10) != (code *)0x0) {
      uVar2 = (**(code **)(*param_1 + 0x10))
                        (param_1[1],param_2,param_3,auStack_24[0],param_5,param_6);
    }
  }
  memw();
  return uVar2;
}

