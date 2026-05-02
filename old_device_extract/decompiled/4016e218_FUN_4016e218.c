// Function : FUN_4016e218
// Address  : 0x4016e218
// Size     : 148 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e218(byte param_1)

{
  undefined4 uVar1;
  short sVar2;
  ushort local_30;
  ushort uStack_2e;
  
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xa4))(0x62,1,5,7,0);
  FUN_4016e1b8(uVar1,&local_30);
  if (param_1 < 3) {
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(100,0,4,local_30 & 0xff | 0x40);
    if (param_1 != 2) goto LAB_4016e295;
  }
  else {
    sVar2 = 8;
    if (7 < (short)local_30) {
      sVar2 = -8;
    }
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(100,0,4,sVar2 + local_30 & 0xff | 0x40);
  }
  sVar2 = 8;
  if (7 < (short)uStack_2e) {
    sVar2 = -8;
  }
  uStack_2e = sVar2 + uStack_2e;
LAB_4016e295:
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(100,0,7,uStack_2e & 0xff | 0x40);
  return;
}

