// Function : FUN_40163ebc
// Address  : 0x40163ebc
// Size     : 73 bytes


short FUN_40163ebc(byte param_1,undefined2 param_2,short param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = 10;
  if (7 < param_1) {
    sVar1 = 0x10;
  }
  sVar3 = 0x120;
  if ((((1 < (byte)(param_1 - 0x29)) && (sVar3 = 0xc0, 4 < param_1)) && (sVar3 = 0x60, 7 < param_1))
     && (sVar3 = 0x24, param_1 < 0x10)) {
    sVar3 = 0x14;
  }
  sVar2 = FUN_40163e38(param_1,param_2);
  return sVar2 + sVar1 + param_3 + sVar3;
}

