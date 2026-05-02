// Function : FUN_40164f34
// Address  : 0x40164f34
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40164f34(uint param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (param_1 & 0xff) * 4;
  uVar4 = *(uint *)(&DAT_3ffc06e0 + iVar1);
  if (((uVar4 & 1 << ((byte)param_3 & 0x1f)) != 0) &&
     (iVar3 = (*(code *)&SUB_4008b33c)
                        (*(int *)(&DAT_3ffc7d14 + (param_3 & 0xff) * 4) + 0x1f,param_2,6),
     iVar3 == 0)) {
    uVar2 = (uint)(0xfffffffefffffffe >> 0x20 - (param_3 & 0x1f));
    *(uint *)(&DAT_3ffc06e0 + iVar1) = uVar4 & uVar2;
    _DAT_3ffc06f0 = _DAT_3ffc06f0 & uVar2;
    memw();
    return;
  }
  FUN_40147fe4(6,0x800,2,0x3f4370b6);
  return;
}

