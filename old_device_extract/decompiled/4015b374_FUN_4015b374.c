// Function : FUN_4015b374
// Address  : 0x4015b374
// Size     : 210 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b374(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  char *pcVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char local_40;
  char cStack_3f;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  
  puVar1 = _DAT_3ffbfdf0;
  iVar5 = 0;
  uVar7 = 0x83;
  iVar8 = 0xd;
  iVar6 = 0xe;
  sVar4 = 0x96c;
  *(undefined1 *)((int)_DAT_3ffbfdf0 + 0x4f) = 0xe;
  pcVar3 = (char *)(puVar1 + 0x15);
  do {
    *(undefined4 *)(pcVar3 + 8) = uVar7;
    *(short *)(pcVar3 + 2) = sVar4;
    memw();
    if (iVar5 == iVar8) {
      *(undefined2 *)((int)puVar1 + 0xf2) = 0x9b4;
      memw();
    }
    if (*pcVar3 == '\0') {
      memw();
      uStack_30 = uVar7;
      iStack_2c = iVar8;
      iStack_28 = iVar6;
      cVar2 = FUN_4015b068(*(undefined2 *)(pcVar3 + 2),*(undefined4 *)(pcVar3 + 8));
      *pcVar3 = cVar2;
      memw();
      iVar6 = iStack_28;
      uVar7 = uStack_30;
      iVar8 = iStack_2c;
    }
    sVar4 = sVar4 + 5;
    iVar5 = iVar5 + 1;
    pcVar3 = pcVar3 + 0xc;
  } while (iVar5 != iVar6);
  cStack_3f = '\0';
  memw();
  if (*_DAT_3ffbfc54 == '\x01') {
    memw();
    memw();
    local_40 = '\x01';
  }
  else {
    local_40 = _DAT_3ffbfc54[0x3f3];
    cStack_3f = _DAT_3ffbfc54[0x3fc];
  }
  *puVar1 = param_1;
  *(undefined1 *)(puVar1 + 1) = 0xff;
  memw();
  memw();
  FUN_4015b1ec(&local_40);
  FUN_4015b284(&local_40);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(_DAT_3ffbfdf0 + 9,0x4015b000,0);
  (**(code **)(_DAT_3ffc1a34 + 0xf4))(_DAT_3ffbfdf0 + 0xe,0x4015b000,1);
  return;
}

