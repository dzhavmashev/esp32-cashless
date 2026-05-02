// Function : FUN_40126034
// Address  : 0x40126034
// Size     : 197 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40126034(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  int *in_t0;
  undefined4 uStack_44c;
  undefined1 *puStack_448;
  undefined4 uStack_444;
  undefined1 *puStack_440;
  undefined4 uStack_43c;
  undefined4 uStack_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  undefined1 auStack_424 [512];
  undefined1 auStack_224 [512];
  undefined4 **local_24 [9];
  
  memw();
  pppuVar3 = local_24;
  memw();
  local_24[0] = _DAT_3ffc5708;
  memw();
  iVar2 = FUN_40128a90(param_3,auStack_424,0x200,*(undefined4 *)(*param_1 + 0x44));
  if (-1 < iVar2) goto LAB_4012609c;
  do {
    param_2 = 0xffffffff;
    param_1 = in_t0;
    while( true ) {
      pppuVar1 = _DAT_3ffc5708;
      memw();
      memw();
      if ((undefined4 ***)*pppuVar3 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      pppuVar3 = pppuVar1;
      param_6 = param_1;
      in_t0 = param_1;
LAB_4012609c:
      memw();
      iVar2 = FUN_40128a90(param_6,auStack_224,0x200,*(undefined4 *)(*param_1 + 0x44));
      if (iVar2 < 0) break;
      uStack_438 = 2;
      uStack_434 = *(undefined4 *)(*param_1 + 0x44);
      uStack_43c = param_7;
      uStack_428 = param_8;
      memw();
      uStack_44c = param_2;
      puStack_448 = auStack_424;
      uStack_444 = param_4;
      puStack_440 = auStack_224;
      uStack_430 = param_5;
      uStack_42c = uStack_434;
      param_2 = FUN_401020e4(*param_1,0x20,5,&uStack_44c,&uStack_438,param_9);
      param_1 = in_t0;
    }
  } while( true );
}

