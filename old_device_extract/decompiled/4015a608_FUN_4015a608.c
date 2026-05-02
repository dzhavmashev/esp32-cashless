// Function : FUN_4015a608
// Address  : 0x4015a608
// Size     : 268 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015a608(uint param_1,byte *param_2,char param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [40];
  
  if ((*param_2 & 1) == 0) {
    if ((param_1 & 0xfffffffb) != 1) {
      uVar4 = FUN_4015a240(param_2);
      goto LAB_4015a63d;
    }
    uVar4 = (uint)(byte)(param_3 + 8);
  }
  else {
    uVar4 = (uint)(byte)(param_3 + 1);
    FUN_4015a200(param_2,uVar4);
LAB_4015a63d:
    if (param_1 == 0) {
      FUN_4015fdf8(uVar4);
      return 0;
    }
  }
  if (param_1 == 2) {
    (*(code *)&SUB_4008b3d0)(auStack_40,param_4,0x18);
    (*(code *)&SUB_4008b3d0)(auStack_30,param_4 + 0x18,8);
    param_4 = param_4 + 0x10;
    puVar5 = auStack_28;
    uVar6 = 8;
  }
  else {
    puVar5 = auStack_40;
    uVar6 = param_5;
  }
  (*(code *)&SUB_4008b3d0)(puVar5,param_4,uVar6);
  iVar1 = FUN_4015a254(1,param_2);
  memw();
  FUN_4015fa0c(1,param_1 & 0xff,param_3,param_2,uVar4,auStack_40,param_5 & 0xff,1,iVar1 != 0);
  FUN_40162d48();
  puVar2 = (undefined2 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(0xa8);
  if (puVar2 == (undefined2 *)0x0) {
    return 0x101;
  }
  FUN_4015a5d4();
  if (param_1 == 2) {
    *(undefined4 *)(puVar2 + 0x50) = 0x3ffbfee8;
    *(undefined4 *)(puVar2 + 0x4c) = 1;
    *(undefined4 *)(puVar2 + 0x4e) = 0;
    memw();
  }
  else {
    if (param_1 == 3) {
      uVar3 = 0x3ffbfeb8;
    }
    else {
      if ((param_1 & 0xfffffffb) != 1) goto LAB_4015a700;
      uVar3 = 0x3ffbff00;
    }
    *(undefined4 *)(puVar2 + 0x50) = uVar3;
  }
LAB_4015a700:
  *puVar2 = (short)uVar4;
  memw();
  memw();
  FUN_4015a190(uVar4,puVar2);
  return 0;
}

