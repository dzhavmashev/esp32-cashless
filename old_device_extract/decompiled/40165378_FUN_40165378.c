// Function : FUN_40165378
// Address  : 0x40165378
// Size     : 207 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40165378(undefined4 param_1,undefined2 param_2,int param_3,int param_4,ushort param_5,
                 int param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_6 != 3) && (_DAT_3ffc7dd8 != (code *)0x0)) {
    memw();
    iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(0x2c);
    if (iVar4 != 0) {
      if (param_5 < 0x10) {
        (*(code *)&SUB_4008b530)(iVar4 + 0x1c,0,6);
      }
      else {
        (*(code *)&SUB_4008b3d0)(iVar4 + 0x1c,param_4 + 10,6);
      }
      uVar5 = (DAT_3ffc0728 & 0xf) << 0x10;
      uVar6 = *(uint *)(param_3 + 8);
      *(uint *)(param_3 + 8) = uVar6 & 0xfff0ffff | uVar5;
      *(uint *)(param_3 + 8) = uVar6 & 0xff00ffff | uVar5 | (DAT_3ffc0729 & 0xf) << 0x14;
      memw();
      (*(code *)&SUB_4008b3d0)(iVar4,param_3,0x1c);
      uVar3 = FUN_40189cfc();
      *(undefined4 *)(iVar4 + 0x24) = param_1;
      *(undefined1 *)(iVar4 + 8) = uVar3;
      *(undefined2 *)(iVar4 + 0x28) = param_2;
      pcVar2 = _DAT_3ffc7dd8;
      uVar1 = _DAT_3ffc7dd4;
      memw();
      *(bool *)(iVar4 + 0x22) = param_6 == 1;
      memw();
      memw();
      (*pcVar2)(uVar1,iVar4);
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar4);
    }
  }
  return;
}

