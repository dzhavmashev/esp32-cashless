// Function : FUN_401651ac
// Address  : 0x401651ac
// Size     : 200 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401651ac(byte param_1,undefined4 param_2,uint param_3,undefined1 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *(int *)(&DAT_3ffc7d14 + (param_3 & 0xff) * 4);
  bVar1 = (byte)param_3;
  if (iVar2 == 0) {
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x88);
    *(int *)(&DAT_3ffc7d14 + (param_3 & 0xff) * 4) = iVar2;
    if (iVar2 == 0) {
      memw();
      FUN_40147fe4(6,0x200,1," no mem");
      return 0;
    }
  }
  else {
    if (((_DAT_3ffc06f0 & 1 << (bVar1 & 0x1f)) != 0) &&
       (((*(uint *)(&DAT_3ffc06e0 + (uint)param_1 * 4) & 1 << (bVar1 & 0x1f)) == 0 ||
        (iVar3 = (*(code *)&SUB_4008b33c)(iVar2 + 0x1f,param_2,6), iVar3 != 0)))) {
      FUN_40147fe4(6,0x800,2,0x3f4370bd);
      return 0;
    }
    (*(code *)&SUB_4008b530)(iVar2,0,0x88);
  }
  uVar5 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  _DAT_3ffc06f0 = _DAT_3ffc06f0 | uVar5;
  iVar3 = (uint)param_1 * 4;
  uVar4 = *(uint *)(&DAT_3ffc06e0 + iVar3);
  *(undefined1 *)(iVar2 + 0x25) = param_4;
  *(byte *)(iVar2 + 0x80) = bVar1;
  *(byte *)(iVar2 + 0x81) = param_1;
  *(undefined1 *)(iVar2 + 0x26) = 0;
  memw();
  *(uint *)(&DAT_3ffc06e0 + iVar3) = uVar4 | uVar5;
  memw();
  (*(code *)&SUB_4008b3d0)(iVar2 + 0x1f,param_2,6);
  FUN_4016512c(param_3 & 0xff);
  return iVar2;
}

