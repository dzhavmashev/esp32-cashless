// Function : FUN_4014a9bc
// Address  : 0x4014a9bc
// Size     : 379 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014a9bc(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  iVar1 = FUN_40165e7c();
  iVar1 = (iVar1 + -1) * 3;
  uVar7 = (uint)(iVar1 - (iVar1 >> 0x1f)) >> 1 & 0xff;
  uVar5 = 0;
  if (((0xf < uVar7) && (uVar5 = 1, 0x1f < uVar7)) && (uVar5 = 2, 0x3f < uVar7)) {
    uVar5 = 3;
  }
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,100);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(param_1 + 0x158) = 0x4080000;
  if (((param_1 == _DAT_3ffc8800) && (*(char *)(_DAT_3ffbfc54 + 0x9d) != '\x01')) ||
     ((param_1 == _DAT_3ffc8804 && (*(char *)(_DAT_3ffbfc54 + 0x3fb) != '\x01')))) {
    memw();
    iVar1 = FUN_40154d88(1);
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x9000000;
    }
  }
  memw();
  iVar2 = FUN_40165e40();
  iVar3 = FUN_40165e4c();
  iVar4 = FUN_40165e58();
  iVar1 = _DAT_3ffc8800;
  if (iVar2 != 0) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x200000;
    memw();
    FUN_4014a128(param_1 != iVar1);
  }
  if (iVar3 != 0) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x100000;
  }
  if (iVar4 != 0) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x400000;
  }
  uVar7 = *(uint *)(param_1 + 0x158);
  *(uint *)(param_1 + 0x158) = uVar7 | 0x800000;
  uVar6 = 0x110c;
  if ((uVar7 & 0x80000) != 0) {
    uVar6 = 0x4110c;
  }
  *(undefined4 *)(param_1 + 0x160) = uVar6;
  if ((uVar7 & 0x300000) != 0) {
    *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x160) | 0x10000;
  }
  *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x160) | 0x20000;
  *(ushort *)(param_1 + 0x15c) = uVar5 | 0x1c;
  *(undefined2 *)(param_1 + 0x164) = 0;
  memw();
  *(undefined1 *)(param_1 + 0x167) = 1;
  *(undefined1 *)(param_1 + 0x166) = 1;
  memw();
  memw();
  FUN_4015fb68(&PTR_s_ardware_4014a83c,0xd,1);
  FUN_4015ec38(3,2,&DAT_4014ac38);
  FUN_4015ec38(3,0,&LAB_4014acf4);
  FUN_4015eb50(3,1,&DAT_4014a170);
  FUN_4015eb50(3,0,&DAT_4014a170);
  FUN_4015ec38(3,1,"xfC?^fC?6a");
  FUN_4015eb50(3,2,&PTR_s__4014a710);
  return;
}

