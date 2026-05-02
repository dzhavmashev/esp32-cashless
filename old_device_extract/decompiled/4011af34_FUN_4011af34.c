// Function : FUN_4011af34
// Address  : 0x4011af34
// Size     : 56 bytes


/* WARNING: Removing unreachable block (ram,0x4011af71) */
/* WARNING: Removing unreachable block (ram,0x4011af75) */
/* WARNING: Removing unreachable block (ram,0x4011af82) */
/* WARNING: Removing unreachable block (ram,0x4011af94) */

undefined4 FUN_4011af34(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24 [9];
  
  if (param_2 == (undefined4 *)0x0) {
    param_2 = local_24;
  }
  iVar1 = (*(code *)&SUB_4008fec4)(*(undefined4 *)*param_1,param_2,0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    *param_2 = 0;
  }
  else {
    uVar2 = 0;
    if (iVar1 != 1) {
      (*(code *)&SUB_40094c54)("e mutex",0x16b,"ox_free"," failed");
      memw();
      return 0;
    }
  }
  memw();
  return uVar2;
}

