// Function : FUN_40139c0c
// Address  : 0x40139c0c
// Size     : 74 bytes


undefined4
FUN_40139c0c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

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
    if (*(code **)(*param_1 + 0x14) != (code *)0x0) {
      memw();
      uVar2 = (**(code **)(*param_1 + 0x14))
                        (param_1[1],param_2,param_3,auStack_24[0],param_5,param_6,param_7,param_8);
    }
  }
  memw();
  return uVar2;
}

