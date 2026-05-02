// Function : FUN_400e9b4c
// Address  : 0x400e9b4c
// Size     : 154 bytes


undefined4
FUN_400e9b4c(int *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 auStack_28 [40];
  
  FUN_400f057c(auStack_28);
  iVar1 = FUN_400e8470(param_2,auStack_28);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_400ea068(param_1[0xb],auStack_28,param_3,param_2,param_1[0xe],0,0,0,0,param_4,
                         param_5,(char)param_1[0xf],param_1[0x15]);
    param_1[0xc] = iVar1;
    if (iVar1 < 0) {
      uVar4 = func_0x40085c04();
      uVar2 = FUN_401847ec("tStatus");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),1000,0);
      FUN_4012105c("ure.cpp",uVar3,uVar2,0xa6,"t: %d\r\n",iVar1);
      (**(code **)(*param_1 + 0x3c))(param_1);
      uVar2 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 8) = 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}

