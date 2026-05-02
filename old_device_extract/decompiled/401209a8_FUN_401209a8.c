// Function : FUN_401209a8
// Address  : 0x401209a8
// Size     : 66 bytes


undefined4 FUN_401209a8(int param_1,byte *param_2,undefined1 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0x101;
  if ((int)(*param_2 + 2 + param_4) < 0x41) {
    puVar2 = (undefined1 *)(param_1 + (uint)*param_2);
    puVar2[1] = (char)param_4;
    *puVar2 = param_3;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puVar2 + 2,param_5,param_4);
    uVar1 = 0;
    *param_2 = (char)param_4 + '\x02' + *param_2;
    memw();
  }
  memw();
  return uVar1;
}

