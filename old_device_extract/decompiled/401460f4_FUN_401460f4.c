// Function : FUN_401460f4
// Address  : 0x401460f4
// Size     : 339 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401460f4(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  FUN_4014605c();
  iVar2 = FUN_40150e2c();
  if (iVar2 == 0) {
    FUN_401460a4();
    return 0x3008;
  }
  if (*(int *)(iVar2 + 4) == -1) {
    (*(code *)&SUB_4008b530)(iVar2 + 4,0,0x24);
    (*(code *)&SUB_4008b530)(iVar2 + 0x2f,0,0x40);
  }
  (*(code *)&SUB_4008b3d0)(param_1,iVar2 + 8,0x20);
  (*(code *)&SUB_4008b3d0)(param_1 + 0x20,iVar2 + 0x2f,0x40);
  *(uint *)(param_1 + 0x60) = (uint)*(byte *)(iVar2 + 0x35c);
  *(undefined1 *)(param_1 + 100) = *(undefined1 *)(iVar2 + 0x92);
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(param_1 + 0x65,iVar2 + 0x93,6);
  *(undefined1 *)(param_1 + 0x6b) = *(undefined1 *)(iVar2 + 0x90);
  memw();
  *(undefined2 *)(param_1 + 0x6c) = *(undefined2 *)(iVar2 + 0x9a);
  memw();
  *(uint *)(param_1 + 0x70) = (uint)*(byte *)(iVar2 + 0x35d);
  *(uint *)(param_1 + 0x78) = (uint)*(byte *)(iVar2 + 0x35f);
  *(undefined1 *)(param_1 + 0x74) = *(undefined1 *)(iVar2 + 0x35e);
  memw();
  uVar3 = 1;
  *(bool *)(param_1 + 0x7c) = *(char *)(iVar2 + 0x360) != '\0';
  memw();
  *(bool *)(param_1 + 0x7d) = *(char *)(iVar2 + 0x361) != '\0';
  memw();
  uVar4 = *(byte *)(iVar2 + 0x362) & 1;
  uVar1 = *(ushort *)(param_1 + 0x7e);
  *(ushort *)(param_1 + 0x7e) = uVar1 & 0xfffe | uVar4;
  memw();
  uVar5 = (*(byte *)(iVar2 + 0x363) & 1) << 1;
  *(ushort *)(param_1 + 0x7e) = uVar1 & 0xfffc | uVar4 | uVar5;
  memw();
  uVar6 = (*(byte *)(iVar2 + 0x364) & 1) << 2;
  *(ushort *)(param_1 + 0x7e) = uVar1 & 0xfff8 | uVar4 | uVar5 | uVar6;
  memw();
  *(ushort *)(param_1 + 0x7e) =
       uVar1 & 0xfff0 | uVar4 | uVar5 | uVar6 | (*(byte *)(iVar2 + 0x498) & 1) << 3;
  memw();
  if ((*(char *)(iVar2 + 0x499) != '\0') && (uVar3 = 3, *(char *)(iVar2 + 0x499) == '\x01')) {
    uVar3 = 2;
  }
  *(undefined4 *)(param_1 + 0x84) = uVar3;
  *(undefined1 *)(param_1 + 0x88) = *(undefined1 *)(iVar2 + 0x49a);
  memw();
  if (_DAT_3ffc8864 != 0) {
    *(undefined1 *)(param_1 + 0x6b) = *(undefined1 *)(iVar2 + 0x90);
    memw();
  }
  memw();
  FUN_401460a4();
  return 0;
}

