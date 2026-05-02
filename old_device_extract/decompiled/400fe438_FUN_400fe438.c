// Function : FUN_400fe438
// Address  : 0x400fe438
// Size     : 191 bytes


void FUN_400fe438(undefined4 *param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  puVar4 = (undefined1 *)*param_1;
  if (0 < *param_3) goto LAB_400fe489;
  memw();
  memw();
  memw();
  memw();
  uVar5 = *(uint *)(puVar4 + 0x60);
  memw();
  memw();
  memw();
  if ((uVar5 >> 2 & 0x7ff) < (uVar5 >> 0xd & 0x7ff)) {
    memw();
    uVar1 = uVar5 >> 0xd & 0x7ff;
    memw();
LAB_400fe483:
    iVar2 = uVar1 - (uVar5 >> 2 & 0x7ff);
  }
  else {
    memw();
    memw();
    if ((uVar5 >> 0xd & 0x7ff) < (uVar5 >> 2 & 0x7ff)) {
      memw();
      uVar1 = (uVar5 >> 0xd & 0x7ff) + 0x80;
      memw();
      goto LAB_400fe483;
    }
    iVar2 = 0;
    if ((*(uint *)(puVar4 + 0x1c) & 0xff) != 0) {
      iVar2 = 0x80;
    }
  }
  *param_3 = iVar2;
LAB_400fe489:
  iVar2 = *param_3;
  puVar6 = (undefined4 *)&DAT_3ff40000;
  if ((puVar4 != &DAT_3ff40000) && (puVar6 = (undefined4 *)&DAT_3ff50000, puVar4 != &DAT_3ff50000))
  {
    puVar6 = (undefined4 *)&DAT_3ff6e000;
  }
  iVar3 = 0;
  while (iVar2 != iVar3) {
    memw();
    puVar4 = (undefined1 *)(param_2 + iVar3);
    iVar3 = iVar3 + 1;
    *puVar4 = (char)*puVar6;
    memw();
    memw();
  }
  memw();
  return;
}

