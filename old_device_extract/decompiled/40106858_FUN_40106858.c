// Function : FUN_40106858
// Address  : 0x40106858
// Size     : 88 bytes


undefined4 * FUN_40106858(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  
  puVar1 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = param_2;
    puVar1[4] = param_1;
    puVar1[2] = param_3;
    puVar1[1] = 0;
    *puVar1 = 0;
    memw();
    (*(code *)&SUB_4008b530)(auStack_2c,0,0xc);
    uStack_34 = 0x40106448;
    pcStack_28 = "MK Name";
    memw();
    puStack_30 = puVar1;
    iVar2 = FUN_4011f868(&uStack_34,puVar1 + 3);
    if (iVar2 != 0) {
      (*(code *)&SUB_40094d80)(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}

