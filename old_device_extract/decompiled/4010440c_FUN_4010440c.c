// Function : FUN_4010440c
// Address  : 0x4010440c
// Size     : 141 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010440c(undefined2 param_1)

{
  if (_DAT_3ffc81dc == 0) {
    _DAT_3ffc81dc = 1;
    memw();
    FUN_40103538(0xb);
    FUN_4010323c(0x3ffc7ef0,1,param_1);
    (*(code *)&SUB_40085b60)(0x3ffc80f8);
    FUN_4011f9fc(0x3ffc80f8);
    FUN_4011f9a4(0x3ffc80f8,0x40102d64,0);
  }
  else {
    FUN_40103538(0xc);
    FUN_4010323c(0x3ffc7ef0,1,param_1);
    _DAT_3ffc80f4 = 1;
    memw();
    FUN_4010286c(0,10000);
    (*(code *)&SUB_40085b60)(0x3ffc80f8);
    FUN_4011f9fc(0x3ffc80f8);
    FUN_4011f9a4(0x3ffc80f8,0x40103584,0);
  }
  (*(code *)&SUB_40085b00)(0x3ffc80f8,60000,0);
  return 0;
}

