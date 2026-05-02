// Function : FUN_4013cea0
// Address  : 0x4013cea0
// Size     : 61 bytes


undefined4 FUN_4013cea0(undefined1 *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (((param_3 & 0xffffffbf) == 0x80) || (uVar1 = 0xffffffe0, param_3 == 0x100)) {
    *param_1 = (char)(param_3 >> 3);
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(param_1 + 2,param_2,param_3 >> 3 & 0xff);
    memw();
    param_1[1] = 0;
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

