// Function : FUN_4011ade8
// Address  : 0x4011ade8
// Size     : 70 bytes


undefined4 FUN_4011ade8(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar2 = *param_1;
  if (param_2 != 0) goto LAB_4011ae0e;
  iVar1 = (*(code *)&SUB_40090010)(uVar2,0xffffffff);
  if (iVar1 != 1) {
    uVar2 = 0xb9;
    while( true ) {
      uVar3 = (*(code *)&SUB_40094c54)("e mutex",uVar2,"ox_post","n value");
      param_2 = (int)((ulonglong)uVar3 >> 0x20);
      uVar2 = (undefined4)uVar3;
LAB_4011ae0e:
      iVar1 = (*(code *)&SUB_40090010)(uVar2,param_2);
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      if (iVar1 == 1) break;
      uVar2 = 0xc1;
    }
  }
  return 0;
}

