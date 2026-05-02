// Function : FUN_40139c80
// Address  : 0x40139c80
// Size     : 48 bytes


undefined4
FUN_40139c80(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffc180;
  if (*param_1 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x18);
    uVar2 = 0xffffc100;
    if (pcVar1 != (code *)0x0) {
      memw();
      uVar2 = (*pcVar1)(param_1[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return uVar2;
}

