// Function : FUN_40109e54
// Address  : 0x40109e54
// Size     : 69 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_40109e54(undefined4 param_1,undefined1 *param_2)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  
  if (_DAT_3ffc5ccc == 0) {
    (*(code *)&SUB_40094c54)("message",0x1f1,"ip_init","tcpip.c");
  }
  local_30 = 1;
  memw();
  uStack_2c = param_1;
  puStack_28 = param_2;
  uStack_24 = FUN_4011b0b4();
  memw();
  FUN_4011ae80(&DAT_3ffc5ccc,&local_30);
  FUN_4011ade8(uStack_24,0);
  return *param_2;
}

