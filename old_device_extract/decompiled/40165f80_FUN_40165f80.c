// Function : FUN_40165f80
// Address  : 0x40165f80
// Size     : 245 bytes


void FUN_40165f80(uint param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5,
                 uint param_6)

{
  uint *puVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  memw();
  FUN_40147fe4(5,0x2000,3,0x3f435bcb,param_1,param_2 & 0xff,*(undefined1 *)param_3,
               *(undefined1 *)((int)param_3 + 1),*(undefined1 *)((int)param_3 + 2),
               *(undefined1 *)((int)param_3 + 3),*(undefined1 *)(param_3 + 1),
               *(undefined1 *)((int)param_3 + 5),param_4 & 0xff,param_5 & 0xffff,param_6 & 0xff);
  iVar2 = param_1 * -0x20;
  memw();
  *(undefined4 *)(iVar2 + 0x3ff73258) = *param_3;
  memw();
  *(uint *)(iVar2 + 0x3ff73254) = (param_2 & 3) << 0x10 | (uint)*(ushort *)(param_3 + 1);
  memw();
  *(uint *)(&DAT_3ff7325c + iVar2) = (param_6 & 0x7f) << 0xd | param_5 & 0xfff;
  puVar1 = (uint *)(&DAT_3ff73250 + iVar2);
  memw();
  memw();
  *puVar1 = *puVar1 & 0x7fffffff;
  memw();
  *(undefined4 *)((0x1ffb993 - param_1) * 0x20) = 0;
  memw();
  *(undefined4 *)(&DAT_3ff73264 + iVar2) = 0;
  memw();
  *puVar1 = (param_4 & 0xf) << 0xc | 0xc0000005;
  memw();
  return;
}

