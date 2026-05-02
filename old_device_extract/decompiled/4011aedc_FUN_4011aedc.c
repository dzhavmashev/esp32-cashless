// Function : FUN_4011aedc
// Address  : 0x4011aedc
// Size     : 85 bytes


undefined4 FUN_4011aedc(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24 [9];
  
  if (param_2 == (undefined4 *)0x0) {
    param_2 = local_24;
  }
  uVar2 = *(undefined4 *)*param_1;
  if (param_3 != 0) goto LAB_4011af0a;
  iVar1 = (*(code *)&SUB_4008fec4)(uVar2,param_2,0xffffffff);
  if (iVar1 != 1) {
    uVar2 = 0x147;
    while( true ) {
      uVar2 = (*(code *)&SUB_40094c54)("e mutex",uVar2,"ryfetch"," failed");
LAB_4011af0a:
      iVar1 = (*(code *)&SUB_4008fec4)(uVar2,param_2);
      if (iVar1 == 0) {
        *param_2 = 0;
        uVar2 = 0xffffffff;
        goto LAB_4011af18;
      }
      if (iVar1 == 1) break;
      uVar2 = 0x150;
    }
  }
  uVar2 = 0;
LAB_4011af18:
  memw();
  return uVar2;
}

