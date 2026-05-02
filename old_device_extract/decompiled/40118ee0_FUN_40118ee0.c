// Function : FUN_40118ee0
// Address  : 0x40118ee0
// Size     : 271 bytes


void FUN_40118ee0(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  char cStack_24;
  
  iVar1 = (int)param_1;
  while (puVar2 = *(undefined4 **)(&DAT_3ffc853c + iVar1 * 0x2c), puVar2 != (undefined4 *)0x0) {
    iVar4 = puVar2[1];
    *(undefined4 *)(&DAT_3ffc853c + iVar1 * 0x2c) = *puVar2;
    iVar3 = *(int *)(iVar4 + 4);
    uStack_34 = *(uint *)(iVar3 + 0x18);
    uStack_30 = *(undefined4 *)(iVar3 + 0x1c);
    uStack_2c = *(undefined4 *)(iVar3 + 0x20);
    uStack_28 = *(undefined4 *)(iVar3 + 0x24);
    if (((uStack_34 & 0xc0ff) == 0x80fe) ||
       (cStack_24 = '\0', ((uStack_34 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
      cStack_24 = *(char *)(*(int *)(&DAT_3ffc8530 + iVar1 * 0x2c) + 0xee) + '\x01';
    }
    memw();
    memw();
    (**(code **)(*(int *)(&DAT_3ffc8530 + iVar1 * 0x2c) + 0xc0))
              (*(int *)(&DAT_3ffc8530 + iVar1 * 0x2c),iVar4,&uStack_34);
    FUN_4010bb10(puVar2[1]);
    FUN_4010b078(0xe,puVar2);
  }
  return;
}

