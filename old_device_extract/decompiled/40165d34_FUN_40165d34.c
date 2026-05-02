// Function : FUN_40165d34
// Address  : 0x40165d34
// Size     : 130 bytes


void FUN_40165d34(undefined1 param_1,byte param_2,undefined1 param_3,undefined4 param_4,uint param_5
                 ,undefined4 param_6,undefined4 param_7,byte param_8,byte param_9)

{
  int iVar1;
  byte local_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 auStack_3d [13];
  uint uStack_30;
  uint uStack_2c;
  
  uStack_30 = (uint)param_8;
  uStack_2c = (uint)param_9;
  memw();
  (*(code *)&SUB_4008b530)(&local_40,0,9);
  memw();
  memw();
  local_40 = param_2;
  uStack_3f = param_1;
  uStack_3e = param_3;
  (*(code *)&SUB_4008b3d0)(auStack_3d,param_4,6);
  FUN_401662e4(param_5,param_6,param_7,&local_40);
  if ((param_2 < 2) && (1 < (int)param_5)) {
    iVar1 = (param_2 + 4) * 4;
    *(uint *)(iVar1 + 0x3ffc0708) =
         *(uint *)(iVar1 + 0x3ffc0708) | 1 << 0x20 - (0x20 - (param_5 & 0x1f));
  }
  memw();
  FUN_401664f4(local_40,uStack_3f,uStack_30,uStack_2c);
  return;
}

