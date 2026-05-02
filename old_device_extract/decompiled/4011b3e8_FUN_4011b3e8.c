// Function : FUN_4011b3e8
// Address  : 0x4011b3e8
// Size     : 64 bytes


undefined4 FUN_4011b3e8(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 - 0x30U < 0x10) && (param_2 != 0)) {
    (*(code *)&SUB_4008b530)(param_2,0,0x3c);
    *(undefined4 *)(param_2 + 4) = 0xc000;
    memw();
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_40173a8c();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  memw();
  return uVar2;
}

