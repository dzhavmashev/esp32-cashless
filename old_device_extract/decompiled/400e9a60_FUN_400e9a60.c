// Function : FUN_400e9a60
// Address  : 0x400e9a60
// Size     : 140 bytes


bool FUN_400e9a60(int *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_400ea068(param_1[0xb],param_2,param_3,param_4,param_1[0xe],param_5,(char)param_1[0x16]
                       ,param_6,param_7,0,0,(char)param_1[0xf],param_1[0x15]);
  param_1[0xc] = iVar1;
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 8) = 1;
  }
  else {
    uVar4 = func_0x40085c04();
    uVar2 = FUN_401847ec("tStatus");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),1000,0);
    FUN_4012105c("ure.cpp",uVar3,uVar2,0x90,"connect",iVar1);
    (**(code **)(*param_1 + 0x3c))(param_1);
  }
  return -1 < iVar1;
}

