// Function : FUN_40109db4
// Address  : 0x40109db4
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40109db4(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (_DAT_3ffc5ccc == 0) {
    (*(code *)&SUB_40094c54)("message",0x163,"ait_sem","tcpip.c");
  }
  puVar2 = (undefined4 *)FUN_4010b058(8);
  uVar3 = 0xff;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 3;
    puVar2[1] = param_1;
    puVar2[2] = param_2;
    memw();
    cVar1 = FUN_4011aeb0(&DAT_3ffc5ccc,puVar2);
    uVar3 = 0;
    if (cVar1 != '\0') {
      FUN_4010b078(8,puVar2);
      uVar3 = 0xff;
    }
  }
  return uVar3;
}

