// Function : FUN_400f2ec0
// Address  : 0x400f2ec0
// Size     : 138 bytes


undefined4 FUN_400f2ec0(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (param_1 != 0) {
    if (DAT_3ffc54f7 == '\0') {
      FUN_400f2e88(param_1);
      DAT_3ffc54f7 = '\x01';
    }
    uVar1 = FUN_400f2e08(param_1,1);
    if (uVar1 != 0) {
      puVar3 = &DAT_3ff40000;
      if ((*(char *)(param_1 + 4) != '\0') &&
         (puVar3 = &DAT_3ff50000, *(char *)(param_1 + 4) != '\x01')) {
        puVar3 = &DAT_3ff6e000;
      }
      memw();
      memw();
      *(uint *)(puVar3 + 0x18) = *(uint *)(puVar3 + 0x18) & 0xfffffffe;
      DAT_3ffc54f7 = 0;
      uVar2 = FUN_400f36bc();
      uVar2 = uVar2 / uVar1;
      if (uVar2 < 0xb) {
        iVar4 = 1;
        if (uVar2 + 0xf2d19b9b < 10 - uVar2) {
          iVar4 = 0;
        }
      }
      else {
        iVar4 = 2;
      }
      return *(undefined4 *)
              ("[%6u][E][%s:%u] %s(): UART%d changing TX pin failed.\r\n" + iVar4 * 4 + 0x31);
    }
  }
  return 0;
}

