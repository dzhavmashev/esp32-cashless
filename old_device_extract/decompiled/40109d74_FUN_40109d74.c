// Function : FUN_40109d74
// Address  : 0x40109d74
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40109d74(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (_DAT_3ffc5ccc == 0) {
    (*(code *)&SUB_40094c54)("message",0x13f,"allback","tcpip.c");
  }
  puVar1 = (undefined4 *)FUN_4010b058(8);
  uVar2 = 0xff;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    memw();
    FUN_4011ae80(&DAT_3ffc5ccc,puVar1);
    uVar2 = 0;
  }
  return uVar2;
}

